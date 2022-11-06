#include<stdio.h>
#include<math.h>

main()
{
    int n,m,i,j;
    scanf("%d %d", &n, &m);
    char mtr[n][m];
    int score[m];
    for(i=0;i<n;i++) scanf("%s", mtr[i]);

    for(j=0;j<m;j++) {
        score[j]=0;
        for(i=0;i<n;i++) {
            if(mtr[i][j]=='1') score[j]++;
        }
    }

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(mtr[i][j]=='1' && score[j]==1) break;
        }
        if(j==m) {
            printf("YES\n");
            break;
        }
    }
    if(i==n) printf("NO\n");
}