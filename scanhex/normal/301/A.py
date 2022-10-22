def numneg(arr):
    s = 0
    for x in arr:
        if x < 0:
            s += 1
    return s
def negmax(arr):
    maxi = float('inf')
    for x in arr:
        if abs(x) < maxi:
            maxi = abs(x)
    return -maxi
def sumabs(arr):
    s = 0
    for x in arr:
        s += abs(x)
    return s
n = int(input())
a = list(map(int, input().split()))
if numneg(a) % 2 == 0 or n % 2 == 1:
    print(sumabs(a))
else:
    print(sumabs(a) + negmax(a) * 2)