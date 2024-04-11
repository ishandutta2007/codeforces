#include <stdio.h>
#include <math.h>

struct Point{
    int x, y;
};
Point p1, p2;

int r;

double dist(Point a, Point b)
{
    return sqrt(((double)a.x-b.x)*((double)a.x-b.x)+((double)a.y-b.y)*((double)a.y-b.y));
}

            
int main()
{
    scanf("%d %d %d %d %d", &r, &p1.x, &p1.y, &p2.x, &p2.y);
    if(dist(p1, p2)>=(double)r)
    {
        printf("%lf %lf %lf", (double)p1.x, (double)p1.y, (double)r);
    }
    else
    {
        if(p1.x==p2.x)
        {
            printf("%lf %lf %lf", (double)p1.x, (double)(p2.y+p1.y-r)/2, (double)(p2.y-p1.y+r)/2);
        }
        else
        {
            printf("%lf %lf %lf", (double)p1.x+(((double)p2.x-p1.x)-((double)r*(p2.x-p1.x)/dist(p1, p2)))/2, (double)p1.y+(((double)p2.y-p1.y)-(double)r*(p2.y-p1.y)/dist(p1, p2))/2, (dist(p1, p2)+r)/2);
        }
    }
    return 0;
}