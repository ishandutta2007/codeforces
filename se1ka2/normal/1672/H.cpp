#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int t0[200005], t1[200005];
    t0[0] = t1[0] = 0;
    for(int i = 1; i < n; i++){
        t0[i] = t0[i - 1];
        t1[i] = t1[i - 1];
        if(s[i] == '0' && s[i - 1] == '0') t0[i]++;
        if(s[i] == '1' && s[i - 1] == '1') t1[i]++;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
		l--;
        r--;
        int c0 = t0[r] - t0[l];
        int c1 = t1[r] - t1[l];
        cout << max(c0, c1) + 1 << "\n";
    }
}