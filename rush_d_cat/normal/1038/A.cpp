#include <iostream>
using namespace std;
const int N = 100000 + 10;
int cnt[30];
int n, k;
char s[N];
int main() {
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++) cnt[s[i]-'A'+1]++;
    int mn=N;
    for(int i=1;i<=k;i++) mn = min(mn, cnt[i]);
    cout << k * mn << endl;
}