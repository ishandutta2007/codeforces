#include <iostream>
#include <cstring>
using namespace std;
const int NICO = 100000+10;
char s1[NICO], s2[NICO];
int cnt1, cnt2;

int main() {
    scanf("%s %s", s1+1, s2+1);
    int n = strlen(s1 + 1);
    for(int i=1;i<=n;i++) {
        if(s1[i] == '4') cnt1 ++;
        if(s2[i] == '4') cnt2 ++;   
    }
    int d = abs(cnt1 - cnt2), cnt = 0;
    for(int i=1;i<=n;i++) {
        if(s1[i] == '4' && s2[i] == '4') {
            cnt ++;
        }
    }
    int sum = cnt2 - cnt + cnt1 - cnt;
    int ans = d + (sum - d) / 2;
    cout << ans << endl;
}   


/*
[cnt] [cnt2 - cnt] [cnt1 - cnt] [res]
 
4444  777 444444444444 77777
4444  444 777777777777 77777
*/