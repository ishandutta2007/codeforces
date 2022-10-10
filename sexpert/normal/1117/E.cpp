    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAXN = 1e4 + 6;
    int perm[MAXN];
     
    string qry(string s) {
        cout << "? " << s << '\n';
        cout.flush();
        string res;
        cin >> res;
        if(res == "0")
            exit(0);
        return res;
    }
     
    int main() {
        string s;
        cin >> s;
        int n = s.length();
        string q = "";
        for(int i = 0; i < n; i++)
            q += ('a' + (i % 26));
        string r = qry(q);
        for(int i = 0; i < n; i++)
            perm[i] += (int)(r[i] - 'a');
     
        q = "";
        for(int i = 0; i < n; i++)
            q += ('a' + ((i/26) % 26));
        r = qry(q);
        for(int i = 0; i < n; i++)
            perm[i] += 26*(int)(r[i] - 'a');
     
        q = "";
        for(int i = 0; i < n; i++)
            q += ('a' + (((i/26)/26) % 26));
        r = qry(q);
        for(int i = 0; i < n; i++)
            perm[i] += 26*26*(int)(r[i] - 'a');
     
        string t = s;
        for(int i = 0; i < n; i++) {
            //cout << perm[i] << endl;
            t[perm[i]] = s[i];
        }
        cout << "! " << t << '\n';
        cout.flush();
    }