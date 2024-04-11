#include <bits/stdc++.h>
using namespace std;
typedef long double LD;
const LD eps = 1e-13;
LD query(vector<pair<LD, LD> > pnts) {
	printf("? %d\n", (int)pnts.size());
	fflush(stdout);
	for (const auto& [x,y]: pnts) {
		printf("%.12Lf %.12Lf\n", x, y);
		fflush(stdout);
	}
	LD ans;
	scanf("%Lf",&ans);
	return ans;
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);

    auto solve = [&](bool rev) {
    	if (rev == true) swap(n, m);
	    vector<pair<LD,LD> > vec;
	    constexpr LD kIterationLen = 1e-3;
	    LD iteration = kIterationLen;
	    LD cur_x = 0;
	    
	    vec.push_back({0, m});
	    for (int i = 1; i <= n; i ++) {
	    	vec.push_back({cur_x, m - eps});
			vec.push_back({cur_x, 0});
			vec.push_back({cur_x + iteration, 0});
			vec.push_back({cur_x + iteration, m - eps});
			cur_x += 1;
			iteration += kIterationLen;
		}
		vec.push_back({n, m - eps});
		vec.push_back({n, m});
		if (rev) for (auto & p: vec) swap(p.first, p.second);
		LD pos = query(vec);
		LD inclued_pos;
		int part = int(pos / kIterationLen + 1e-9);
		if (abs(part - pos / kIterationLen) < 1e-9) {
			inclued_pos = part - 1 + part * kIterationLen;
		} else {
			inclued_pos = part;
		}
		if (rev == true) swap(n, m);
		return inclued_pos;
	};

	LD inclued_x = solve(/*rev = */false);
	//cout << inclued_x << "\n";
	LD inclued_y = solve(/*rev = */true);
	//printf("%.9f %.9f\n", inclued_x, inclued_y);
	
	vector<pair<LD,LD> > qx;
	qx.push_back({0,0}); qx.push_back({0,m}); qx.push_back({inclued_x, m}); qx.push_back({inclued_x, 0});
	LD sx = query(qx);

	vector<pair<LD, LD> > qy;
	qy.push_back({0,0}); qy.push_back({n,0}); qy.push_back({n, inclued_y}); qy.push_back({0, inclued_y});
	LD sy = query(qy);

	printf("! %.9Lf %.9Lf\n", inclued_x - sx, inclued_y - sy);
	fflush(stdout);

}