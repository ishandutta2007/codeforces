import sys

input = sys.stdin.readline

q = int(input())

for i in range(q):
    n = int(input())
    x = int(input())
    pw10 = (10 ** n)
    y = pw10 + 1 - x;
    if(y >= x):
        print(y)
    else:
        y = pw10 + pw10 // 10 + 11 - x
        print(y)