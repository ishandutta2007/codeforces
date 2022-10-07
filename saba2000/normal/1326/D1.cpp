#include<bits/stdc++.h>
using namespace std;
int lps[4000009];
main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        int x= 0;
        while(s[x] == s[n - x - 1] && x + 1 <= n/2)
            x++;
        string A = "", B = "";
        for(int i = 0; i < x; i++)
            A += s[i];
        for(int i = n-x; i < n; i++)
            B += s[i];

        string t = "";
        for(int i = x; i < n - x; i++)
            t += s[i];
        string u = t;
        reverse(t.begin(), t.end());
        string X = u;
        X+='*'; X +=t;
        while (i < X.size()) {
            if (X[i] == X[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int p = lps[X.size()-1];
        X = t; X+='*'; X +=u;
        len = 0; i = 1;
        while (i < X.size()) {
            if (X[i] == X[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int su = lps[X.size()-1];
        if(p < su)  p = su; else t = u;
        cout<<A;
        if(t.size())
        for(int i =0 ; i <p; i++)
            cout<<t[i];
        cout<<B<<endl;
    }

}