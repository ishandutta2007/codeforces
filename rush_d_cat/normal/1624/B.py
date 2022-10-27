t = int(input())
for iter in range(t):
    a, b, c = map(int, input().split(' '))
    if (2 * b - a) % c == 0 and 2 * b > a: print("YES")
    elif (2 * b - c) % a == 0 and 2 * b > c: print("YES")
    elif (a + c) % (2 * b) == 0: print("YES")
    else: print("NO")