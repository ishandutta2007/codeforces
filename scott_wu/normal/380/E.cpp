#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
const int MAXN = 300100;
const int MAXP = 4000100;
const int P = (1 << 20);
typedef long long ll;
typedef long double ld;

int N;
int arr[MAXN];

int q[MAXN];
int qlo, qhi;

//int fless[MAXN], fmore[MAXN]; // first one before i that's >, first one after i that's >=

int seg[MAXP];

int fless (int loc, int val) // loc of first element before loc at least val
{
	int cloc = loc + P;
	
	while (true)
	{
		if (cloc % 2 == 1 && seg[cloc-1] >= val)
		{
			cloc--;
			break;
		}
		cloc /= 2;
		if (cloc <= 1)
			break;
	}
	if (cloc <= 1) return -1;
	
	while (cloc < P)
	{
		if (seg[2*cloc+1] >= val)
			cloc = 2 * cloc + 1;
		else
			cloc = 2 * cloc;
	}
	return cloc - P;
}

int fmore (int loc, int val) // first element after loc at least val
{
	int cloc = loc + P;
	
	while (true)
	{
		if (cloc % 2 == 0 && seg[cloc+1] >= val)
		{
			cloc++;
			break;
		}
		cloc /= 2;
		
		if (cloc <= 1)
			break;
	}
	if (cloc <= 1) return N;
	
	while (cloc < P)
	{
		if (seg[2*cloc] >= val)
			cloc = 2 * cloc;
		else
			cloc = 2 * cloc + 1;
	}
	return cloc - P;
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 2 * P; i++)
		seg[i] = -1e9;
	for (int i = P; i < P + N; i++)
		seg[i] = arr[i - P];
	for (int i = P - 1; i >= 1; i--)
		seg[i] = max (seg[2*i], seg[2*i+1]);
	
	/*qlo = qhi = 0;
	for (int i = 0; i < N; i++)
	{
		while (qlo < qhi && arr[i] >= arr[q[qhi-1]])
			qhi--;
		
		if (qlo == qhi)
			fless[i] = -1;
		else
			fless[i] = q[qhi-1];
		q[qhi] = i;
		qhi++;
	}
	
	qlo = qhi = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		while (qlo < qhi && arr[i] > arr[q[qhi-1]])
			qhi--;
		
		if (qlo == qhi)
			fmore[i] = N;
		else
			fmore[i] = q[qhi-1];
		q[qhi] = i;
		qhi++;
	}*/
	
	ld ans = 0.0;
	for (int i = 0; i < N; i++)
	{
		//cout << fless (i, arr[i]) << " " << fmore (i, arr[i]) << "\n";
		
		ld left = 0.0, right = 0.0;
		ld pl = 1.0, pr = 1.0;
		
		int itemp = i;
		for (int j = 0; itemp >= 0 && j < 40; j++)
		{
			int f = fless (itemp, arr[i] + 1);
			left += (itemp - f) * pl;
			itemp = f;
			pl /= 2.0;
		}
		itemp = i;
		for (int j = 0; itemp < N && j < 40; j++)
		{
			int f = fmore (itemp, arr[i]);
			right += (f - itemp) * pr;
			itemp = f;
			pr /= 2.0;
		}
		
		//cout << left << " " << right << "\n";
		ans += arr[i] / 2.0 * (left / N) * (right / N);
	}

	cout << fixed << setprecision (9);
	cout << ans << "\n";
	return 0;
}