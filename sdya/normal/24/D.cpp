#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

void TridiagonalSolve (const double *a, const double *b, double *c, double *d, double *x, unsigned int n)
{
	/* Modify the coefficients. */
	c[0] /= b[0];	/* Division by zero risk. */
	d[0] /= b[0];	/* Division by zero would imply a singular matrix. */
	for (int i = 1; i < n; i++){
		double id = 1 / (b[i] - c[i-1] * a[i]);  /* Division by zero risk. */
		c[i] *= id;	                         /* Last value calculated is redundant. */
		d[i] = (d[i] - d[i-1] * a[i]) * id;
	}
 
	/* Now back substitute. */
	x[n - 1] = d[n - 1];
	for (int i = n - 2; i >= 0; i--)
		x[i] = d[i] - c[i] * x[i + 1];
}

int n, m;
int p, q;

double prev[2000];
double a[2000], b[2000], c[2000], d[2000], x[2000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d", &n, &m);
    scanf("%d%d", &p, &q);
    q --;
    if (m == 1)
    {
        printf("%.10lf\n", 2.0 * (n - p));
        return 0;
    }
    for (int i = 1; i <= m; i ++) prev[i] = 0.0;
    for (int i = n - 1; i >= p; i --)
    {
        for (int j = 0; j < m; j ++)
            a[j] = b[j] = c[j] = d[j] = 0.0;
        b[0] = b[m - 1] = 2.0 / 3.0;
        c[0] = a[m - 1] = - 1.0 / 3.0;
        d[0] = prev[0] / 3.0 + 1;
        d[m - 1] = prev[m - 1] / 3.0 + 1;

        for (int j = 1; j < m - 1; j ++)
        {
            b[j] += 0.75;
            a[j] = c[j] = - 0.25;
            d[j] = prev[j] / 4.0 + 1.0;
        }
        TridiagonalSolve(a, b, c, d, x, m);
        for (int j = 0; j < m; j ++) prev[j] = x[j];
    }


    printf("%.10lf\n", prev[q]);

    return 0;
}