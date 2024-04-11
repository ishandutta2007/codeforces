#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
string str;
bool f[MAXN],g[MAXN];
int main()
{
	cin>>str;
	int n=str.size();
	int k=0,r=1;
    while (r*2<=n) r*=2;
    int m=n-r+1; memset(f,true,sizeof(f));
    for(int i=0;i<m;i++)
    {
        char ch='z';
        for(int j=0;j<r;j++) if(f[j]&&str[j+i]<ch) ch=str[j+i];
        printf("%c",ch);
        memset(g,false,sizeof(g));
        for (int j=0;j<r;j++) 
        	if(f[j]&&str[j+i]==ch)
        	{
	            if(g[j]) continue; 
	            int c=r-1-j;
	            for (int j=c;;j=(j-1)&c)
	            {
	                g[r-1-j]=true;
	                if(!j) break;
	            }
        	}
        for(int j=0;j<r;j++) f[j]=g[j];
    }
	return 0;
}