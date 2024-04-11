#include<iostream> //andrew

using namespace std; //yolo

int Y, X[1000001];

int N, M; //scott

int main() {//andrew
cin >> N >> M; //scott
Y = 0; for(int i = 0; i < N; i++) cin >> X[i];
for (int i = 0; i < M; i++) //scott
{
int T; cin >> T; if (T == 1)//scott
{ int v, x; cin >> v >> x;
X[v-1] = x - Y;
} //andrew
else if (T == 2)
{ int y; cin >> y, Y+=y;}
else //scott
{ int q; cin >> q;
cout << X[q-1] + Y << "\n"; //andrew
}
}
return 0;}