#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 333;
const double eps = 1e-8;

int mat[N][N];
int n, k;
double result[N];

struct Node {
    double x, y;
    Node(double x, double y) : x(x), y(y) {}
    Node() {}
    
};

double Cross(Node a, Node b, Node c) {
    b.x -= a.x, b.y -= a.y;
    c.x -= a.x, c.y -= a.y;
    return b.x * c.y - c.x * b.y; 
}

Node calc(const Node &p1, const Node &p2, const Node &p3, const Node &p4) {
    double k;
    /*
    if ((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y)==0) return 0;
    if ((p4.x-p3.x)*(p1.y-p3.y)-(p4.y-p3.y)*(p1.x-p3.x)==0&&
        (p2.x-p1.x)*(p1.y-p3.y)-(p2.y-p1.y)*(p1.x-p3.x)==0) return 0;
    */
     k=((p4.x-p3.x)*(p1.y-p3.y)-(p4.y-p3.y)*(p1.x-p3.x))/((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y));
     //k1=((p2.x-p1.x)*(p1.y-p3.y)-(p2.y-p1.y)*(p1.x-p3.x))/((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y));
     return Node(p1.x+k*(p2.x-p1.x), p1.y+k*(p2.y-p1.y));
}

vector<Node> res;

void modify(vector<Node> &tmp, const Node &a, const Node &b) {
    res.clear();
    if (a.y > tmp[0].y) {
        res.push_back(a);
    } else {
        res.push_back(tmp[0]);
    }
    
    for(int i = 1; i < (int)tmp.size(); i++) {
        
        if (fabs(Cross(tmp[i - 1], tmp[i], b) - Cross(tmp[i - 1], tmp[i], a)) > eps) {
            Node c = calc(tmp[i - 1], tmp[i], a, b);
            if (c.x < tmp[i].x + eps && c.x > tmp[i - 1].x - eps)
                res.push_back(c);
        }
    
        if (Cross(a, b, tmp[i]) > -eps) {
            res.push_back(tmp[i]);
        }
    }
    
    if (b.y > tmp.back().y + eps) {
        res.push_back(b);
    }
    
    tmp = res;
}

int main() {
    
    
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++)
            scanf("%d", &mat[i][j]);
    }
    
    
    vector<Node> points;
    for(int i = 1; i <= k; i++) {
        //printf("%d\n", i);
        points.clear();
        points.push_back(Node(0, 0));
        points.push_back(Node(1, 0));
        double ori = 0;
        for(int j = 1; j <= n; j++) {
            modify(points, Node(0, mat[j][i - 1]), Node(1, mat[j][i]));
            double tmp = 0;
            for(int k = 1; k < (int)points.size(); k++) {
                tmp += (points[k - 1].y + points[k].y) * (points[k].x - points[k - 1].x) / 2.0;
            }
            
            //printf("%d\n", (int)points.size());
            
            result[j] += tmp - ori;
            ori = tmp;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        printf("%.12lf\n", result[i]);
    }
    
    return 0;
}