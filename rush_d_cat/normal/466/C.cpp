#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n,a[N]; LL s[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    if(s[n]%3) return !printf("0\n");
    vector<int> v1,v2;
    for(int i=1;i<n;i++) if(s[i] == s[n]/3) v1.push_back(i);
    for(int i=2;i<n;i++) if(s[i] == s[n]/3 * 2) v2.push_back(i);
    long long res=0;

    //for(auto x: v1) printf("# %d\n", x);
    for(int i=0,j=0;i<v2.size();i++) {
        while(j<v1.size() && v1[j] < v2[i]) j++;
        res+=j;
    }
    cout<<res<<endl;
}