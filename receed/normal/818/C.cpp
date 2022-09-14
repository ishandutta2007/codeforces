#include <bits/stdc++.h>

using namespace std;




int main(){
	int d, n, m;
	cin >> d >> n >> m;
	int x1, y1, x2, y2;
	vector<vector<int> > a(d, vector<int>(4));
	vector<int> pl(n + 1, 0), pr(n + 2, 0), pt(m + 1, 0), pb(m + 2, 0);
	for(int i = 0; i < d; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		pl[x1]++;
		pr[x2]++;
		pt[y1]++;
		pb[y2]++;
		a[i][0] = x1; a[i][1] = y1;
		a[i][2] = x2; a[i][3] = y2;
	}
	for(int i = 0; i < n; i++)
		pl[i + 1] += pl[i];
	for(int i = 0; i < m; i++)
		pt[i + 1] += pt[i];
	for(int i = n; i >= 1; i--)
		pr[i] += pr[i + 1];
	for(int i = m; i >= 1; i--)
		pb[i] += pb[i + 1];
	int l, r, t, b, cl, cr, ct, cb;
	cin >> l >> r >> t >> b;
	for(int i = 0; i < d; i++){
		cl = pl[a[i][2] - 1];
		cr = pr[a[i][0] + 1];
		ct = pt[a[i][3] - 1];
		cb = pb[a[i][1] + 1];
		if(a[i][0] == a[i][2]){
			ct--; cb--;
		}
		else{
			cl--; cr--;
		}
		//cout<<cl<<cr<<ct<<cb<<endl;
		if(l == cl && r == cr && t == ct && b == cb){
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
}