#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
int L[100005],R[100005],F[100005],l[100005],r[100005],P[100005];
int main(void)
{
    BetterIO;
   	int Case=1;cin>>Case;while(Case--)
   	{
   		int N;cin>>N;
   		for(int i=1;i<=N;i++)F[i]=0,P[i]=i;
   		for(int i=1;i<=N;i++)
   		{
   			cin>>l[i]>>r[i];
   			for(int j=l[i];j<=r[i];j++)F[j]++;
   		}
   		std::sort(P+1,P+1+N,[&](int x,int y){return (l[x]==l[y]?r[x]>r[y]:l[x]<l[y]);});
   		// for(int i=1;i<=N;i++)L[P[i]]=l[i],R[P[i]]=r[i];
   		for(int i=1;i<=N;i++)L[i]=l[P[i]],R[i]=r[P[i]];
   		for(int i=1;i<=N;i++)
   		{
   			for(int j=L[i];j<=R[i];j++)F[j]--;
   			cout<<L[i]<<' '<<R[i]<<' ';
   			for(int j=1;j<=N;j++)
   			{
   				if(F[j]==0)
   				{
   					F[j]=100000;
   					cout<<j<<'\n';
   					break;
   				}
   			}
   		}
   	}
    return 0;
}