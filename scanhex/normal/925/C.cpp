#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

const int N = 1e5 + 7;
const int LEN = N * 61;

int go[LEN][2];
int cnt[LEN];
int sz = 1;

void add(nagai x)
{
    int v = 0;
    for (int i = 60; i >= 0; i--)
    {
        int c = ((x >> i) & 1);
        if (!go[v][c])
        {
            go[v][c] = sz++;
        }
        v = go[v][c];
        cnt[v]++;
    }
}

void rem(nagai x)
{
    int v = 0;
    for (int i = 60; i >= 0; i--)
    {
        int c = ((x >> i) & 1);
        if (!go[v][c])
        {
            go[v][c] = sz++;
        }
        v = go[v][c];
        cnt[v]--;
    }
}

nagai get(nagai x, int v = 0, int lg = 60, nagai cur = 0, bool lol = false)
{
	if (lg < 60 && (v == 0 || !cnt[v]))
		return -1;
	if (lg == -1)
		return cur;
	int i = lg;
	nagai x1 = x + 1;
	int go0 = 0;
	int go1 = 1;
	if (x >> i & 1)
		swap(go1, go0);
	int mem = go0;
	if ((x1 >> i & 1) && !lol)
		mem = go1;
	if (mem == go0 && (go[v][mem] == 0 || !cnt[go[v][mem]]))
		mem = go1, lol = true;
	nagai cur1 = cur + mem * (1LL << i);
	nagai ans = get(x, go[v][mem], lg - 1, cur1, lol);
	if (ans == -1 && mem == go0)
		mem = go1, ans = get(x, go[v][mem], lg - 1, cur + mem * (1LL << i), true);
	return ans;
}


bool fast(vector<nagai> a)
{
	int n = a.size();
	fill(cnt, cnt + LEN, 0);
	sz = 1;
	for (int i = 0; i < LEN; ++i)
		go[i][0] = go[i][1] = 0;
	sort(a.begin(), a.end());
	nagai cur = a[0];
	vector<bool> used(n);
	used[0] = true;
	for (int i = 1; i < n; ++i)
	{
		add(a[i]);
	}
	vector<nagai> ans;
	ans.push_back(a[0]);
	for (int i = 0; i < n - 1; ++i)
	{ 
		nagai mem = get(cur);
		//cerr << mem << '\n';
		if (mem == -1)
		{
			cout << "No\n";
			return false;
		}
		cur ^= mem;
		ans.push_back(mem);
		rem(mem);
	}
	cout << "Yes\n";
	for (auto& x : ans)
		cout << x << ' ';
	cout << '\n';
	return true;
}
bool stupid(vector <nagai> b)
{
    sort(b.begin(), b.end());
    do
    {
        bool bad = false;
        vector <nagai> c = b;
        for (int i = 1; i < (int) b.size(); i++)
        {
            c[i] ^= c[i - 1];
            if (c[i] <= c[i - 1])
            {
                bad = true;
                break;
            }
        }
        if (!bad)
        {
            return true;
        }
    }
    while (next_permutation(b.begin(), b.end()));
    return false;
}

int main1()
{
	srand(time(0));
	for (int i = 0; i < 1000; ++i)
	{
		int n = 5;
		vector<nagai> a(n);
		for (auto& x : a)
			x = rand() % 10;
//		if (fast(a))
//			cerr << "oemumoe\n";
		if (fast(a) != stupid(a))
		{
			cerr << n << '\n';
			for (auto& x : a)
				cerr << x << ' ';
			cerr << "fail\n";
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<nagai> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	fast(a);
	return 0;
}