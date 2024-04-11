#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200000 + 10;
char s[N]; int n;
int main() {
    scanf("%d%s",&n,s+1);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++) 
        if(s[i]=='8') cnt1++; else cnt2 ++;

    int ans=0;
    while(cnt1) {
        cnt1--;
        if(cnt2+cnt1<10) break;
        ans ++;
        if(cnt2>10) {
            cnt2 -= 10;
        } else {
            cnt1 -= (10-cnt2); cnt2=0;
        }
    }
    cout<<ans<<endl;
}