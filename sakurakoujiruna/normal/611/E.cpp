#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 201111;
const int Inf = 0x3f3f3f3f;

int cri[N];
multiset <int> st;
int erase(int x)
{
	auto it = st.lower_bound(-x);
	if(it != st.end())
	{
		int ret = -*it;
		st.erase(it);
		return ret;
	}
	return -1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int mus[3];
	for(int i = 0; i < 3; i ++)
		cin >> mus[i];
	sort(mus, mus + 3);
	for(int i = 0; i < n; i ++)
	{
		cin >> cri[i];
		st.insert(-cri[i]);
	}
	int offset = 0;
	if(mus[0] + mus[1] + mus[2] < -*st.begin())
	{
		cout << -1 << '\n';
		return 0;
	}
	while(mus[1] + mus[2] < -*st.begin())
	{
		erase(mus[0] + mus[1] + mus[2]);
		offset ++;
	}
	while(mus[0] + mus[2] < -*st.begin())
	{
		erase(mus[1] + mus[2]);
		erase(mus[0]);
		offset ++;
	}
	while(mus[0] + mus[1] < -*st.begin() && mus[2] < -*st.begin())
	{
		erase(mus[0] + mus[2]);
		erase(mus[1]);
		offset ++;
	}
	int type0 = 0;
	int type1 = 0;
	for(auto it = st.begin(); it != st.end(); it ++)
	{
		if(-*it <= mus[0] + mus[1])
			type0 ++;
		if(-*it <= mus[2])
			type1 ++;
	}
	int ans = Inf;
	for(int i = 0; i <= n; i ++)
	{
		ans = min(ans, offset + i + max((max(type0, type1) + 1)/ 2, abs(type0 - type1)));
		for(int j = 0; j < 3; j ++)
		{
			int x = erase(mus[j]);
			if(x != -1 && x <= mus[0] + mus[1])
				type0 --;
			if(x != -1 && x <= mus[2])
				type1 --;
		}
	}
	cout << ans << '\n';
	return 0;
}