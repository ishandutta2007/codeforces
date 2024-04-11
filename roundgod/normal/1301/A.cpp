#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
string a,b,c;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>a; cin>>b; cin>>c;
        bool f=true;
        n=(int)a.size();
        for(int i=0;i<n;i++)
        {
            if((a[i]!=c[i])&&(b[i]!=c[i])) f=false;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}