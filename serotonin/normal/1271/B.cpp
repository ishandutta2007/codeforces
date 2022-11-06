#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

char inv(char x)
{
    if(x=='B') return 'W';
    return 'B';
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string now;
    now=s;

    vector <int> ans;
    for(int i=1; i+1<now.size(); i++) {
        if(now[i]!=now[i-1]) {
            ans.push_back(i+1);
            now[i]=inv(now[i]);
            now[i+1]=inv(now[i+1]);
        }
    }
    if(now[n-1]==now[n-2]) {
        cout << ans.size() << endl;
        for(int i : ans) cout << i << " ";
        return 0;
    }

    now=s;
    now[0]=inv(now[0]);
    now[1]=inv(now[1]);
    ans.clear();
    ans.push_back(1);

    for(int i=1; i+1<now.size(); i++) {
        if(now[i]!=now[i-1]) {
            ans.push_back(i+1);
            now[i]=inv(now[i]);
            now[i+1]=inv(now[i+1]);
        }
    }
    if(now[n-1]==now[n-2]) {
        cout << ans.size() << endl;
        for(int i : ans) cout << i << " ";
        return 0;
    }

    puts("-1");
}