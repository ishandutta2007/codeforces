t = int(input())
for y in range(t):
    s, a, b, c = map(int, input().split())
    print((s//c)+b*((s//c)//a))