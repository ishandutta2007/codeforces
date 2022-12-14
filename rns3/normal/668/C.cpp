#include<bits/stdc++.h>

using namespace std;

int N;
double v1[100009], v2[100009], S[100009], P[100009], Max[100009], Min[100009], eps = 1e-7;

double GetX (double S, double P)
{
    double delt;
    if (S  *S - 4.0 * P < 0.0) delt = 0.0;
    else delt = (double) sqrt ((double) S * S - 4.0 * P);
    return (S + delt) / 2.0;
}

int main(){
scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%lf", &Max[i]), P[i] = P[i - 1] + Max[i];
for (int i=1; i<=N; i++)
    scanf ("%lf", &Min[i]), S[i] = S[i - 1] + Max[i] + Min[i];
for (int i=1; i<=N; i++)
    v1[i] = GetX (S[i], P[i]), v2[i] = S[i] - v1[i];
for (int i=2; i<=N; i++)
    if (v1[i] < v1[i - 1] - eps || v2[i] < v2[i - 1] - eps) swap (v1[i], v2[i]);
for (int i=1; i<=N; i++)
    printf ("%.10f ", v1[i] - v1[i - 1]);
printf ("\n");
for (int i=1; i<=N; i++)
    printf ("%.10f ", v2[i] - v2[i - 1]);
printf ("\n");
return 0;
}