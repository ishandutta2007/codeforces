from math import sqrt
def delit(x):
    for i in range(2, int(sqrt(x)+1)):
        while x % i == 0:
            print(i,end='')
            x//=i
    if x != 1:
        print(x)
delit(int(input()))