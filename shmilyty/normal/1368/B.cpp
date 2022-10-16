#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll k,cnt=1,a[15];
    string s="codeforces";
    cin>>k;
    for(int i=0;i<10;i++)a[i]=1;
    while(cnt<k) {
        for(int i=0;i<10;i++){
            if(cnt<k){
                cnt/=a[i],
                cnt*=a[i]+1,
                a[i]++;		
            }else break;
        }
    }
    for(int i=0;i<10;i++)
        for(int j=1;j<=a[i];j++)
        	cout<<s[i];
    return 0;
}