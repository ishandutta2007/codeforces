#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
vector<pair<char,int> > v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        string s="";
        s+=str[0]; 
        int last=0;
        for(int i=1;i<n;i++) 
        {
            if(str[i]>s.back()) break;
            else if(str[i]<s.back())
            {
                last=s.back();
                s+=str[i];
            } 
            else if(last!=0) s+=str[i]; else break;
        }
        string rs=s; reverse(rs.begin(),rs.end());
        cout<<s+rs<<endl;
    }
    return 0;
}