#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[1002][6];
    int n, i; cin >> n;
    bool ok = false;
    for(i = 1; i <= n; i++)
    {
        cin >> s[i];
        if(s[i][0]=='O'&&s[i][1]=='O'&&!ok)
        {
            s[i][0] = '+';s[i][1] = '+';
            ok=true;
        }

        if(s[i][3]=='O'&&s[i][4]=='O'&&!ok)
        {
            s[i][3] = '+';s[i][4] = '+';
            ok = true;
        }
    }
    if(!ok) cout << "NO"<< endl;
    else{
        cout <<"YES" << endl;
        for(i = 1; i <= n; i++)
        {
            cout << s[i] << endl;
        }
    }
}