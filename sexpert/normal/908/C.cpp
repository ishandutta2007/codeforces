#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, r;
	vector<pair<double, double> > centers, candidates;
	vector<double> ys;
	pair<double, double> best;
	double x, maxy;
	scanf("%d %d", &n, &r);
	while(n--)
	{
		candidates.erase(candidates.begin(), candidates.end());
		ys.erase(ys.begin(), ys.end());
		scanf("%lf", &x);
		for (auto center : centers)
		{
			if(abs(x - center.first) <= 2*r) candidates.push_back(center);
		}
		if(candidates.empty())
		{
			centers.push_back(make_pair(x, double(r)));
			continue;
		}
		maxy = 0.0;
		for (auto center : candidates)
		{
			ys.push_back(center.second + sqrt(4*r*r - (x - center.first)*(x - center.first)));
		}
		for (auto y : ys)
		{
			maxy = max(maxy, y);
		}
		centers.push_back(make_pair(x, maxy));
	}
	for(auto center : centers)
	{
		printf("%lf ", center.second);
	}
}