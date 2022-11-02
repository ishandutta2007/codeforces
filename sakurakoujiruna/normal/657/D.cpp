#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

const int N = 150011;
typedef long long intl;

struct Prob
{
	intl p, t;
	double mins, maxs;
	Prob() { }
	bool operator <(const Prob &rhs) const
	{
		return p * rhs.t > t * rhs.p;
	}
	bool operator ==(const Prob &rhs) const
	{
		return p * rhs.t == t * rhs.p;
	}
	bool operator !=(const Prob &rhs) const
	{
		return p * rhs.t != t * rhs.p;
	}
}prob[N], pb[N];

bool by_p(Prob lhs, Prob rhs)
{
	return lhs.p < rhs.p;
}

bool check(int n, bool debug = false)
{
	sort(pb, pb + n, by_p);
	vector <vector <Prob> > all;
	vector <Prob> tmp;
	for(int i = 0; i < n; i ++)
	{
		tmp.push_back(pb[i]);
		if(i == n - 1 || (pb[i].p != pb[i + 1].p))
		{
			all.push_back(tmp);
			tmp.clear();
		}
	}

	double lmax = -1;
	for(auto &tmp : all)
	{
		for(auto &prob : tmp)
			if(prob.mins < lmax)
				return false;
		for(auto &prob : tmp)
			lmax = max(lmax, prob.maxs);
	}
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	intl sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> prob[i].p;
	for(int i = 0; i < n; i ++)
	{
		cin >> prob[i].t;
		sum += prob[i].t;
	}
	sort(prob, prob + n);

	double left = 0, right = 1;
	for(int _ = 0; _ < 40; _ ++)
	{
		for(int i = 0; i < n; i ++)
			pb[i] = prob[i];
		double mid = (left + right) / 2;
		int lp = 0;
		intl lsum = 0;
		for(int i = 0; i < n; i ++)
		{
			while(pb[lp] != pb[i])
				lsum += pb[lp ++].t;
			pb[i].maxs = (1 - mid * (lsum + pb[i].t) / sum) * pb[i].p;
		}
		lp = n - 1;
		lsum = 0;
		for(int i = n - 1; i >= 0; i --)
		{
			while(pb[lp] != pb[i])
				lsum += pb[lp --].t;
			pb[i].mins = (1 - mid * (sum - lsum) / sum) * pb[i].p;
		}
		/*
		if(_ == 0)
		{
			for(int i = 0; i < n; i ++)
				cout << pb[i].p << ' ' << pb[i].mins << ' ' << pb[i].maxs << '\n';
		}
		*/
		if(check(n, _ == 0))
			left = mid;
		else
			right = mid;
	}
	cout << setprecision(12) << left << '\n';
	return 0;
}