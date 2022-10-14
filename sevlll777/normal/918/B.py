n, m = list(map(int, input().split()))
vez = {}
for i in range(n):
    comm, ip = input().split()
    vez[ip] = comm
for j in range(m):
    co, ip = input().split()
    ip = ip[:-1]
    print(co, ip+';', '#'+vez[ip])