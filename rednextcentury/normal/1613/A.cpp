#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a,p1,b,p2;
        cin>>a>>p1>>b>>p2;
        while(a<1000000000 && p1) a=a*10, p1--;
        while(b<1000000000 && p2) b=b*10, p2--;
        if (p1>p2) cout<<'>'<<endl;
        else if (p2>p1) cout<<'<'<<endl;
        else {
            if (a>b)cout<<'>'<<endl;
            else if (b>a)cout<<'<'<<endl;
            else cout<<'='<<endl;
        }
    }
}