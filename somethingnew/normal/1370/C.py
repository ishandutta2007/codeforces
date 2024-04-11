from math import sqrt
def deli(x):
    cd = 0
    while x % 2 == 0:
        cd += 1
        x //= 2
    ncd = 0
    for i in range(3, int(sqrt(x)) +1):
        while x % i == 0:
            x//=i
            ncd += 1
    if x != 1:
        ncd += 1
    return cd,ncd
def solvetest():
    n = int(input())
    c,nc = deli(n)
    if n == 1:
        print("FastestFinger")
        return
    if n == 2:
        print("Ashishgup")
        return
    if nc >= 2:
        print("Ashishgup")
        return
    if nc == 0:
        print("FastestFinger")
        return
    if c >= 2:
        print("Ashishgup")
    elif c == 1:
        print("FastestFinger")
    else:
        print("Ashishgup")
for i in range(int(input())):
    solvetest()