#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

using namespace std;
const int MAXN = 1000100;
const int BSIZE = 200;
const int NBIN = 5100;

int N, M;
map <int, int> mloc;
int pleft[MAXN], pright[MAXN];

int ploc[MAXN];
int rloc[MAXN];
int bin[NBIN][NBIN];
int bsum[NBIN][NBIN];
int bnum, x = 0;

int f (int z)
{
    return (z - 1 + x) % N + 1;
}

int solve (int h, int v)
{
    int ans = bsum[h/BSIZE][v/BSIZE];
    
    for (int i = h / BSIZE * BSIZE; i < h; i++)
        if (ploc[i] < v)
            ans++;
    for (int i = v / BSIZE * BSIZE; i < v; i++)
        if (rloc[i] < h / BSIZE * BSIZE)
            ans++;
    //cout << h << " " << v << " " << ans << "\n";
    return ans;
}

int main()
{
    //cin >> N;
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
        scanf ("%d", &pleft[i]);
        //cin >> pleft[i];
    for (int i = 0; i < N; i++)
        scanf ("%d", &pright[i]);
        //cin >> pright[i];
    scanf ("%d", &M);
    //cin >> M;
    
    for (int i = 0; i < N; i++)
        mloc[pleft[i]] = i;
    for (int i = 0; i < N; i++)
        ploc[mloc[pright[i]]] = i;
    
    for (int i = 0; i < N; i++)
        mloc[ploc[i]] = i;
    for (int i = 0; i < N; i++)
        rloc[i] = mloc[i];
    
    bnum = (N - 1) / BSIZE + 1;
    
    for (int i = 0; i < NBIN; i++)
        for (int j = 0; j < NBIN; j++)
            bin[i][j] = 0;
    for (int i = 0; i < N; i++)
        bin[i/BSIZE][ploc[i]/BSIZE]++;
    
    for (int i = 0; i < NBIN; i++)
        bsum[i][0] = bsum[0][i] = 0;
    for (int i = 0; i < NBIN - 1; i++)
        for (int j = 0; j < NBIN - 1; j++)
            bsum[i+1][j+1] = bsum[i][j+1] + bsum[i+1][j] - bsum[i][j] + bin[i][j];
    
    for (int i = 0; i < M; i++)
    {
        int l1, l2, r1, r2;
        scanf ("%d %d %d %d", &l1, &r1, &l2, &r2);
        //cin >> l1 >> r1 >> l2 >> r2;
        //cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        l1 = f (l1), r1 = f (r1), l2 = f (l2), r2 = f (r2);
        
        l1--, r1--, l2--, r2--;
        if (l1 > r1) swap (l1, r1);
        if (l2 > r2) swap (l2, r2);
        
        x = solve (r1 + 1, r2 + 1) + solve (l1, l2) - solve (l1, r2 + 1) - solve (r1 + 1, l2);
        printf ("%d\n", x);
        x++;
    }
    //system ("Pause");
    return 0;
}