#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l,r;
string a,b;
vector<int> ans;
bool flipped;
void rev_prefix(string &str,int x)
{
    ans.push_back(x);
}
char get_st(int cur)
{
    char x=a[l];
    if(flipped) return '0'+'1'-x; else return x;
}
char get_ed(int cur)
{
    char x=a[r];
    if(flipped) return '0'+'1'-x; else return x;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>a;
        cin>>b;
        ans.clear();
        flipped=false;
        l=0; r=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(get_ed(i)==b[i]) {if(l<r) r--; else r++; continue;}
            else if(get_st(i)!=b[i])
            {
                rev_prefix(a,i+1);
                flipped=!flipped; if(l<=r) {l++; swap(l,r); } else {l--; swap(l,r);}
            }
            else
            {
                rev_prefix(a,1);
                rev_prefix(a,i+1);
                flipped=!flipped; if(l<=r) {l++; swap(l,r); } else {l--; swap(l,r);}
            }
        }
        printf("%d ",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}