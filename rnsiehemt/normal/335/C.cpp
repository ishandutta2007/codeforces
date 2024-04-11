#include <cstdio>
#include <cstdlib>
#include <algorithm>

struct P {
    int x, y;
    bool operator<(const P &p) const {
        return x < p.x;
    }
};

int R, N;
P p[105];

void win() {
    printf("WIN\n");
    exit(0);
}

void lose() {
    printf("LOSE\n");
    exit(0);
}

int main()
{
    scanf("%d%d", &R, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].x--; p[i].y--;
    }

    if (N == 0) {
        if (R%2 == 1) win();
        else lose();
    }
    else {
        std::sort(p, p+N);

        int sum = 1000000;
        for (int i = 0; i+1 < N; i++) sum += p[i+1].y - p[i].y + p[i+1].x - p[i].x + 1;

        int f = p[0].x+1, l = R - p[N-1].x;
        if (f < 3 && l < 3) {
            sum += f+1 + l+1;
            if (sum % 2 == 1) win();
            else lose();
        }
        else if (f >= 3 && l >= 3) {
            if (sum % 2 == 0) {
                if (f == l) lose();
                else win();
            }
            else {
                if (f == l) win();
                else {
                    if (f > l) std::swap(f, l);
                    if (f%2 == 1 && l%2 == 0 && f+1 == l) lose();
                    else win();
                }
            }
        }
        else win();
    }
}