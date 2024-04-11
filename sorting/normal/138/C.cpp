#include <bits/stdc++.h>

const int N = 1e5 + 7;

int n, m;

struct tree
{
	int a, h, l, r;

	tree()
	{
		a = 0;
		h = 0;
		l = 0;
		r = 0;
	}
};

struct mushroom
{
	int b, z;

	mushroom()
	{
		b = 0;
		z = 0;
	}

	friend bool operator<(mushroom lhs, mushroom rhs)
	{
		return lhs.b < rhs.b;
	}
};

tree t[N];
mushroom msh[N];
int zero[N];

int binary_search_1(int x)
{
	int ls, rs, mid;

	ls = 0;
	rs = m;

	while(ls != rs)
	{
		mid = (ls + rs) >> 1;

		if(msh[mid].b >= x)
			rs = mid;
		else
			ls = mid + 1;
	}

	return ls;
}

int binary_search_2(int x)
{
	int ls, rs, mid;

	ls = 0;
	rs = m;

	while(ls != rs)
	{
		mid = (ls + rs) >> 1;

		//std::cout << msh[mid].b << " " << x << " mid = " << mid << "\n";   

		if(msh[mid].b > x)
			rs = mid;
		else
			ls = mid + 1;

		//std::cout << "l, r: " << ls << ", " << rs << "\n";
	}

	return ls;
}

double res_arr[N];

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m;

	for(int i = 0; i < n; i++)
		std::cin >> t[i].a >> t[i].h >> t[i].l >> t[i].r;

	for(int i = 0; i < m; i++)
		std::cin >>	msh[i].b >> msh[i].z;

	std::sort(msh, msh + m);

	for(int i = 0; i < m; i++)
		res_arr[i] = (double)1.0;

	for(int i = 0; i < n; i++)
	{
		int ind1, ind2, ind3, ind4;

		ind1 = binary_search_1(t[i].a - t[i].h);
		ind2 = binary_search_1(t[i].a);
		ind3 = binary_search_2(t[i].a);
		ind4 = binary_search_2(t[i].a + t[i].h);

		//std::cout << msh[i].b << "\n";
		//std::cout << ind1 << " " << ind2 << " " << ind3 << " " << ind4 << "\n";

		if(ind1 < ind2)
		{
			if(t[i].l == 100)
			{
				zero[ind1]++;
				zero[ind2]--;
			}
			else
			{
				res_arr[ind1] *= (double) ((100.0 - t[i].l) / 100.0);
				res_arr[ind2] *= (double) (100.0 / (100.0 - t[i].l));
			}
		}
		if(ind3 < ind4)
		{
			if(t[i].r == 100)
			{
				zero[ind3]++;
				zero[ind4]--;
			}
			else
			{
				res_arr[ind3] *= (double) ((100.0 - t[i].r) / 100.0);
				res_arr[ind4] *= (double) (100.0 / (100.0 - t[i].r));
			}
		}
	}

	for(int i = 1; i < m; i++)
	{
		res_arr[i] *= (double) res_arr[i-1];
		zero[i] += zero[i-1];
	}

	double res = (double) 0.0;

	for(int i = 0; i < m; i++)
		if(!zero[i])
			res += (double) (res_arr[i] * msh[i].z);

	std::cout << std::fixed << std::setprecision(5) << res << "\n";

	return 0; 	 
}