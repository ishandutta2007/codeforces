#include<cstdio>
#include<iostream>
using namespace std;

long long sa = 0, sb = 0;

int win(int da, int db) {
    if(da == db) {
        return 0;
    } else if(da == 3 && db == 2 || da == 2 && db == 1 || da == 1 && db == 3) {
        return 1;

    } else {
        return -1;
    }
}

void addscore(int da, int db) {
    if(da == db) {
        sa += 0;
    } else if(da == 3 && db == 2 || da == 2 && db == 1 || da == 1 && db == 3) {
        sa ++;
    } else {
        sb ++;
    }
}

int main() {
    long long k;
	int a, b;
    int A[5][5], B[5][5];
    cin>>k>>a>>b;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    int lasta = a, lastb = b;

    if(k < 100) {
        for(long long i = 0; i < k; i++) {
            if(i == 0) {
                addscore(a,b);
                lasta = a;
                lastb = b;
            } else {
                //printf("i = %d, %d %d\n",i, lasta, lastb);
                //printf("B[1][1] = %d",B[1][1]);
                int tmpa = lasta, tmpb = lastb;
                lasta = A[tmpa][tmpb];
                lastb = B[tmpa][tmpb];
                addscore(lasta, lastb);
            }
        }

        cout<<sa<<" "<<sb;

        return 0;
    }


    for(int i = 0; i < 9; i++) {
        int tmpa = lasta, tmpb = lastb;
        lasta = A[tmpa][tmpb];
        lastb = B[tmpa][tmpb];
    }
    //printf("lasta = %d lastb = %d\n", lasta, lastb);

    int roundlen = 1;
    long long sar = 0;
    long long sbr = 0;
    if(win(lasta, lastb) == 1) {
        sar ++;
        //printf("%d wins %d\n", lasta, lastb);
    } else if(win(lasta, lastb) == -1) {
        sbr ++;
        //printf("%d loses %d\n", lasta, lastb);
    }
    int starta = A[lasta][lastb];
    int startb = B[lasta][lastb];
    while(lasta != starta || lastb != startb) {
        if(win(starta, startb) == 1) {
            sar ++;
            //printf("%d wins %d\n", starta, startb);
        } else if(win(starta, startb) == -1) {
            sbr ++;
            //printf("%d loses %d\n", starta, startb);
        }
        roundlen++;
        int tmpa = starta, tmpb = startb;
        starta = A[tmpa][tmpb];
        startb = B[tmpa][tmpb];
    }
    //printf("roundlen = %d\n", roundlen);
    //printf("sar = %d, sbr = %d\n", sar, sbr);
    long long roundnum = 0;
    roundnum = (k - 11) / roundlen;



    sa += roundnum * sar;
    sb += roundnum * sbr;

    //printf("sa = %d sb = %d", sa,sb);

    //printf("roundnum = %d", roundnum);

    for(long long i = 0; i < k - (long long)roundnum * roundlen; i++) {
        if(i == 0) {
            addscore(a,b);
            lasta = a;
            lastb = b;
        } else {
            //printf("i = %d, %d %d\n",i, lasta, lastb);
            //printf("B[1][1] = %d",B[1][1]);
            int tmpa = lasta, tmpb = lastb;
            lasta = A[tmpa][tmpb];
            lastb = B[tmpa][tmpb];
            addscore(lasta, lastb);
        }
    }

    cout<<sa<<" "<<sb;
}