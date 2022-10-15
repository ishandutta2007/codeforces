#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second
#define x1 daksida 
#define y1 daskdsia
#define x2 doakdos
#define y2 dakoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    string ans="";
    for(int i=1;i<=min(n,k);i++)
    {
        string s="";
        for(int j=0;j<k;j++)
            s+=str[j%i];
        if(ans=="") ans=s;
        else if(s<ans) ans=s;
    }
    cout<<ans<<endl;
}