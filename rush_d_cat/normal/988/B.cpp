#include <iostream>
#include <algorithm>
using namespace std;
const int N = 102;
int n;
string s[N];
bool cmp(string s1, string s2) {
    return s1.length() < s2.length();
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n,cmp);
    bool ok=1;
    for(int i=2;i<=n;i++) {
        if (s[i].find(s[i-1]) == -1) {
            ok = 0;
        }
    }
    if (!ok) {
        cout<<"NO"<<endl; return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<s[i]<<endl;
}