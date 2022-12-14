#include<bits/stdc++.h>
using namespace std;
#define ll long long
string toString(int x){
    string ret="";
    while(x){
        ret+=char('0'+(x%10));
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string ret="";
    for (int i=2;i<=n;i++){
        if (n%i==0){
            ret+=toString(i);
            n/=i;
            i--;
        }
    }
    cout<<ret<<endl;
}