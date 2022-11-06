#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=105;
bool vis[sz];
string s[sz];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> s[i];

    vector <string> one,two;
    for(int i=0; i<n; i++) {
        string now=s[i];
        reverse(now.begin(), now.end());

        for(int j=i+1; j<n; j++) {
            if(vis[j]) continue;
            if(now==s[j]) {
                one.push_back(s[i]);
                two.push_back(s[j]);
                vis[j]=1, vis[i]=1;
                break;
            }
        }
    }

    string bonus="";
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        string now=s[i];
        reverse(now.begin(), now.end());
        if(now==s[i]) bonus=s[i];
    }

    cout << m*2*one.size()+bonus.size() << endl;
    for(auto s : one) cout << s;
    cout << bonus;
    reverse(two.begin(), two.end());
    for(auto s : two) cout << s;
    cout << endl;
}