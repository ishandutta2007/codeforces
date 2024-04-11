#include<bits/stdc++.h>
using std::cin;
using std::cout;
using u32 = unsigned;
const int L = 1 << 18;
const int M = 2e5 + 20;
int n, m;
int dp[L];

inline void up(int & x, int y) {
	if(x < y) x = y;
}

struct segment_tree
{
	int tree[L << 1];
	inline void upt(u32 pos, int v)
	{
		for(tree[pos += L] = v;pos >>= 1;)
			tree[pos] = std::max(tree[pos << 1], tree[pos << 1 | 1]);
	}
	inline int ask(u32 l, u32 r) const {
		int res = 0;
		for(l += L - 1, r += L + 1;l + 1 != r;l >>= 1, r >>= 1)
		{
			if((l & 1) == 0) up(res, tree[l ^ 1]);
			if((r & 1) == 1) up(res, tree[r ^ 1]);
		}
		return res;
	}
};
segment_tree seg0, seg1;

std::set<int> set;
int height[L];

inline void remove(int id)
{
	seg0.upt(id, 0);
	seg1.upt(height[id], 0);
	dp[id] = 0;
}

inline void re_calc(int id, int type)
{
	if(type)
	{
		dp[id] = seg0.ask(id + 1, M) + 1;
	} 
	else
	{
		dp[id] = seg1.ask(height[id], M) + 1;
	}
	seg0.upt(id, dp[id]);
	seg1.upt(height[id], dp[id]);
}

int which[L];
inline void re_update(std::vector<int>& update_pos, int update_type)
{
	for(int cur : update_pos)
	{
		remove(cur);
	}
	for(int cur : update_pos)
	{
		re_calc(cur, update_type);
	}
}
int main()
{
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;++i)
	{
		int type, pos, height;
		cin >> type;
		if(type == 1)
		{
			cin >> pos >> height;
			set.emplace(pos);
			height = m - i + height;
			::height[pos] = height;
			which[height] = pos;
			std::vector<int> update_pos = {pos};
			for(int i = height - 1;i >= height - 10 && i >= 0;--i) {
				if(which[i]) {
					update_pos.push_back(which[i]);
				}
			}
			sort(update_pos.begin(), update_pos.end(), [](int x, int y){
					return ::height[x] > ::height[y];
			});
			re_update(update_pos, 1);
		}
		else
		{
			cin >> pos;
			auto iter = set.begin(); advance(iter, pos - 1);
			int id = *iter;
			remove(id);
			std::vector<int> update_pos(set.begin(), iter);
			reverse(update_pos.begin(), update_pos.end());
			re_update(update_pos, 0);
			which[::height[id]] = 0;
			::height[id] = 0;
			set.erase(iter);
		}
		cout << seg0.tree[1] << '\n';
	}
}