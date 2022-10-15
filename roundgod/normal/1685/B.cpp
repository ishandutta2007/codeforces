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
int n,t,a,b,c,d;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        cin>>str;
        n=(int)str.size();
        int cnta=0;
        for(int i=0;i<n;i++) if(str[i]=='A') cnta++;
        if(cnta!=a+c+d) {puts("NO"); continue;}
        if(n-cnta!=b+c+d) {puts("NO"); continue;}
        int last=0;
        int all=0,sumA=0,sumB=0;
        vector<int> A,B;
        A.clear(); B.clear();
        for(int i=1;i<n;i++)
        {
            if(str[i]==str[i-1])
            {
                int l=last,r=i-1;
                if(r-l+1>=2)
                {
                    if((r-l+1)%2==1) all+=(r-l+1)/2;
                    else
                    {
                        if(str[last]=='A') 
                        {
                            A.push_back((r-l+1)/2-1);
                            sumA+=(r-l+1)/2;
                        }
                        else 
                        {
                            B.push_back((r-l+1)/2-1);
                            sumB+=(r-l+1)/2;
                        }
                    }
                }
                last=i;
            }
        }
        int l=last,r=n-1;
        if(r-l+1>=2)
        {
            if((r-l+1)%2==1) all+=(r-l+1)/2;
            else
            {
                if(str[last]=='A') 
                {
                    A.push_back((r-l+1)/2-1);
                    sumA+=(r-l+1)/2;
                }
                else 
                {
                    B.push_back((r-l+1)/2-1);
                    sumB+=(r-l+1)/2;
                }
            }
        }
        //printf("sumA=%d sumB=%d all=%d\n",sumA,sumB,all);
        if(sumA+sumB+all<c+d) {puts("NO"); continue;}
        if(sumA+all>=c&&sumB+all>=d) {puts("YES"); continue;}
        if(sumA+all<c)
        {
            sumA+=all;
            sort(B.begin(),B.end(),greater<int>());
            int cnt=1,tmp=sumA;
            for(int i=0;i<(int)B.size();i++)
            {
                if(sumA+B[i]>=c) break;
                cnt++;
                sumA+=B[i];
            }
            if(tmp+sumB-cnt<c+d) puts("NO"); else puts("YES");
        }
        else
        {
            sumB+=all;
            sort(A.begin(),A.end(),greater<int>());
            int cnt=1,tmp=sumB;
            for(int i=0;i<(int)A.size();i++)
            {
                if(sumB+A[i]>=d) break;
                cnt++;
                sumB+=A[i];
            }
            if(sumA+tmp-cnt<c+d) puts("NO"); else puts("YES");
        }
    }
    return 0;
}