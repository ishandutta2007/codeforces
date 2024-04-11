    #include <bits/stdc++.h>
    using namespace std;
     
    int n;
    int qs = 0;
     
    int qry(char t, int x) {
        qs++;
        cout << t << " " << x << '\n';
        cout.flush();
        int r;
        cin >> r;
        if(r == -1)
            exit(0);
        return r;
    }
     
    int main() {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        cin >> n;
        int lo = 0, hi = 1e9;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(qry('>', mi) == 0)
                hi = mi;
            else
                lo = mi + 1;
        }
        int mx = lo;
        int d = 0;
        //cout << mx << endl;
        while(qs < 60) {
            int q = rng()%n + 1;
            int x = qry('?', q);
            d = __gcd(d, mx - x);
        }
        cout << "! " << mx - d*(n - 1) << " " << d << endl;
        cout.flush();
    }