#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
bool del[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int n=(int)str.size();
        for(int i=0;i<n;i++) del[i]=false;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1]&&!del[i-1]) {del[i]=true; cnt++;}
            if(!del[i]&&i>=2&&str[i]==str[i-2]&&!del[i-2]) {del[i]=true; cnt++;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}