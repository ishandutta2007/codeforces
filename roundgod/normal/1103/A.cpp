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
int n,k,a[MAXN];
string str;
int cnt1,cnt2;
int main()
{
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
        {
            printf("%d %d\n",cnt1*2+1,1);
            cnt1++;if(cnt1==2) cnt1=0;
        }
        else
        {
            printf("%d %d\n",cnt2+1,3);
            cnt2++; if(cnt2==4) cnt2=0;
        }
    }
    return 0;
}