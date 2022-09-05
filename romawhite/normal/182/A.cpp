//#pragma comment(linker, "/STACK:33554432")
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>
#include <queue>
#include <map>

using namespace std;

#define MAX 1000

long long Ax, Bx, Ay, By;
long long N;
long long a, b;

long long absz(long long a)
{
    return a >= 0 ? a : -a;
}

struct Line
{
    long long x1, y1, x2, y2;
};

Line lines[1000];

long long dist(Line line, long long x, long long y)
{
    if (line.x1 == line.x2)
    {
        if ( (line.y1 - y) * (y - line.y2) >= 0 )
            return absz(line.x1 - x) * absz(line.x1 - x);           
    }
    if (line.y1 == line.y2)
    {
        if ( (line.x1 - x) * (x - line.x2) >= 0 )
            return absz(line.y1 - y) * absz(line.y1 - y);           
    }
    return min(
        (line.x1 - x) * (line.x1 - x) + (line.y1 - y) * (line.y1 - y),
        (line.x2 - x) * (line.x2 - x) + (line.y2 - y) * (line.y2 - y)
            );
}

long long dist(Line l1, Line l2)
{
    long long r1 = min(dist(l1, l2.x1, l2.y1), dist(l1, l2.x2, l2.y2));
    long long r2 = min(dist(l2, l1.x1, l1.y1), dist(l2, l1.x2, l1.y2));
    return min(r1, r2);
}

int main()
{
    cin >> a >> b;
    cin >> Ax >> Ay >> Bx >> By;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;

    double res = -1;
    if ( (Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay) <= a * a)
    {
        res = sqrt((double)(Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay));
    }
    else
    {
        int mas[MAX];
        for (int i = 0; i < MAX; i++)
            mas[i] = -1;
        queue<int> q;
        for (int i = 0; i < N; i++)
            if (dist(lines[i], Ax, Ay) <= a * a)
            {
                mas[i] = 1;
                q.push(i);
            }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = 0 ; i < N; i++)
            {
                long long dd = dist(lines[v], lines[i]);
                if (mas[i] == -1 && dd <= a * a)
                {
                    if (dd > 0)
                        mas[i] = mas[v] + 1;
                    else
                        mas[i] = mas[v];
                    q.push(i);
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            long long dd = dist(lines[i], Bx, By);
            if (dd <= a * a && mas[i] != -1)
            {
                double d = mas[i] * (a + b) + sqrt((double) dd);
                if (res == -1)
                    res = d;
                else
                    res = min(res, d);
            }
        }


    }
            cout << res;
    return 0;
}