#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
priority_queue<P> pque1;
priority_queue<P, vector<P>, greater<P> >pque2;
string str;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        pque2.push(P(x,i));
    }
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
        {
            P p=pque2.top();
            pque2.pop();
            printf("%d ",p.S);
            pque1.push(p);
        }
        else
        {
            P p=pque1.top();
            pque1.pop();
            printf("%d ",p.S);
        }
    }
    return 0;
}