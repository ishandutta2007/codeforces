#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
int main(void)
{
    BetterIO;
   	int Case=1;cin>>Case;while(Case--)
   	{
   		int N,M,A,B,C,D;cin>>N>>M>>A>>B>>C>>D;
   		int CN=1,CM=1,Ans=0;
   		while(A!=C&&B!=D)
   		{
   			Ans++;
   			if(A==N)CN=-1;
   			if(A==1)CN=1;
   			if(B==M)CM=-1;
   			if(B==1)CM=1;
   			A+=CN;
   			B+=CM;
   			// cout<<A<<' '<<B<<endl;
   		}
   		cout<<Ans<<'\n';
   	}
    return 0;
}