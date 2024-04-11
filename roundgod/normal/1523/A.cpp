#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string str;
vector<int> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        cin>>str;
        v.clear();
        for(int i=0;i<n;i++) if(str[i]=='1') v.push_back(i);
        for(int i=0;i<n;i++)
        {
            bool f=false;
            int val1=INF,val2=INF,id1=-1,id2=-1;
            for(auto x:v) 
            {
                if(max(x-i,i-x)<val1)
                {
                    val2=val1; id2=id1; 
                    val1=max(x-i,i-x);
                    id1=i;
                }
                else if(max(x-i,i-x)<val2)
                {
                    val2=max(x-i,i-x);
                    id2=i;
                }
            }
            if(val1<=m&&val1!=val2) printf("1"); else printf("0");
        }
        puts("");
    }
    return 0;
}