n, h = map(int, input().split())
A = list(map(int, input().split()))
bot = []
for i in range(n):
    cnt = 0
    bot.append(A[i])
    bot.sort(reverse=True)
    for iq in range(0, len(bot), 2):
        cnt += bot[iq]
    if cnt > h:
        print(i)
        exit(0)
print(n)