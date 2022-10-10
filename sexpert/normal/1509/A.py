t = int(input())
for _ in range(t):
    input()
    l = list(map(int, input().split()))
    l.sort(lambda x : x % 2)
    print(' '.join(str(x) for x in l))