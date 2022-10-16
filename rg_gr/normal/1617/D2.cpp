#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
int Ans[1000005],Res[1000005];
int Ask(int A,int B,int C)
{
	cout<<'?'<<' '<<A<<' '<<B<<' '<<C<<endl;
	int X;cin>>X;
	return X^1;
}
int main(void)
{
    BetterIO;
    register int Case=1;cin>>Case;while(Case--)
    {
        int N;cin>>N;
        for(int i=1;i<=N;i++)Ans[i]=-1;
        int P0=0,P1=0;
        for(int i=1;i<=N;i+=3)
        {
        	cout<<'?'<<' '<<i<<' '<<i+1<<' '<<i+2<<endl,cin>>Ans[i],Ans[i]^=1;
        	if(Ans[i]==1)P1=i;else P0=i;
        	if(P1&&P0)break;
        }
        for(int i=1;i<=N;i++)Res[i]=0;
        // for(int i=1;i<=N;i+=3)if(Ans[i]==1)P1=i;else P0=i;
        int A010=Ask(P1,P1+1,P0);
        int A011=Ask(P1,P1+1,P0+1);
        int A012=Ask(P1,P1+1,P0+2);
        int A120=Ask(P1+2,P1+1,P0);
        int A121=Ask(P1+2,P1+1,P0+1);
        int A122=Ask(P1+2,P1+1,P0+2);
        // int A020=Ask(P1,P1+2,P0);
        // int A021=Ask(P1,P1+2,P0+1);
        // int A022=Ask(P1,P1+2,P0+2);
        int S0,S1;
        if(A010&&A011&&A012&&A120&&A121&&A122)
        {
        	S1=P1;
        	// san ge 1
        	Res[P1]=Res[P1+1]=Res[P1+2]=1;
        	int T01=Ask(P0,P0+1,P1);
        	int T12=Ask(P0+2,P0+1,P1);
        	int T02=Ask(P0,P0+2,P1);
        	if(T01&&T12)Res[P0+1]=1,S0=P0;
        	else if(T01&&T02)Res[P0+0]=1,S0=P0+2;
        	else if(T02&&T12)Res[P0+2]=1,S0=P0+1;
        	else S0=P0;
        }
        else
        {
        	int Qwq=0;
        	if(A010==0||A011==0||A012==0)Qwq|=4;
        	if(A120==0||A121==0||A122==0)Qwq|=1;
        	if(Qwq==1)
        	{
        		//110
        		S1=P1;
        		S0=P1+2;
        		Res[P1]=Res[P1+1]=1;
        		Res[P0]=A120;
        		Res[P0+1]=A121;
        		Res[P0+2]=A122;
        	}
        	else if(Qwq==4)
        	{
    			//011
        		Res[P1+2]=Res[P1+1]=1;
				S0=P1;
        		S1=P1+2;
        		Res[P0]=A010;
        		Res[P0+1]=A011;
        		Res[P0+2]=A012;
        	}
        	else
        	{
        		//101
        		Res[P1]=Res[P1+2]=1;
        		S0=P1+1;
        		S1=P1+0;
        		Res[P0]=A120;
        		Res[P0+1]=A121;
        		Res[P0+2]=A122;
        	}
        }
        for(int i=max(P0,P1)+3;i<=N;i++)if((0<=i-P0&&i-P0<=2)||(0<=i-P1&&i-P1<=2));else Res[i]=Ask(S0,S1,i);
        for(int i=1;i<P0&&i<P1;i+=3)
        {
        	if(Ans[i]==1)
        	{
        		int j=i+1,k=i+2;
        		int T=Ask(i,j,S0);
        		if(T)Res[i]=Res[j]=1,Res[k]=Ask(k,S0,S1);
        		else
        		{
        			T=Ask(i,S0,S1);
        			Res[i]=T;
        			Res[j]=T^1;
        			Res[k]=1;
        		}
        	}
        	else
        	{
        		int j=i+1,k=i+2;
        		int T=Ask(i,j,S1);
        		if(T==0)Res[i]=Res[j]=0,Res[k]=Ask(k,S0,S1);
        		else
        		{
        			T=Ask(i,S0,S1);
        			Res[i]=T;
        			Res[j]=T^1;
        			Res[k]=0;
        		}
        	}
        }
        int Tot=0;
        for(int i=1;i<=N;i++)Tot+=Res[i];
        cout<<'!'<<' '<<Tot<<' ';
        
        for(int i=1;i<=N;i++)if(Res[i])cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}