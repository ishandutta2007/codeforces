#include <bits/stdc++.h>

using namespace std;

//vector<int> t;
int n;

/*
int sum (int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta) {
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r) {
	return sum (r) - sum (l-1);
}*/

int main() {
    int q;
    cin >> n >> q;
    
    vector<int> a(q), b(q), c(n), d(n);
    //t.resize(n, 0);
    for(int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        
        a[i]--;
        
        d[a[i]]++;
        if(b[i] != n)
            d[b[i]]--;
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        //c[i] = sum(i, i + 1);
        cnt += d[i];
        c[i] = cnt;
        //cout << c[i] << ' ';
    }
    
    vector<int> p1(n + 1, 0), p2(n + 2, 0);
    int s = 0;
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i - 1] + (c[i - 1] == 1);
        p2[i] = p2[i - 1] + (c[i - 1] == 2);
        //cout << i << ' ' << p1[i] << ' ' << p2[i] << endl;
        s += (c[i - 1] > 0);
        //cout << a[i - 1] << endl;
    }
    //cout << endl << s << endl;
    int ans = 0;
    for(int i = 0; i < q; i++)
        for(int j = 0; j < i; j++) {
            int l = max(a[i], a[j]);
            int r = min(b[i], b[j]);
            
            int cur = s - p1[b[i]] + p1[a[i]] - p1[b[j]] + p1[a[j]];
            
            ///cout << i << ' ' << a[i] << ' ' << b[i] << endl;
            //cout << j << ' ' << a[j] << ' ' << b[j] << endl;
            //cout << l << ' ' << r << ' ' << cur << endl << endl;
            
            if(r <= l) {
                
            } else {
                cur -= p2[r] - p2[l];
                cur += p1[r] - p1[l];
                
            }
             //cout << l << ' ' << r << ' ' << cur << endl << endl;
            ans = max(ans, cur);
        }
        
    cout << ans;
}