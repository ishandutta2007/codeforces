#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int n,m;
bool isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    return false;
}
int main()
{
    cin>>s;cin>>t;
    n=s.size();m=t.size();
    bool f=true;
    if(n!=m) {puts("No"); return 0;}
    for(int i=0;i<n;i++)
    {
        if(isvowel(s[i])!=isvowel(t[i]))
        {
            f=false;
            break;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}