import itertools
arr = [0, 0, 0, 0]
for i in range(4):
    arr[i] = int(input())

def __OR__(x, y):
    return x ^ y

def __AND__(x, y):
    return x & y

def __XOR__(x, y):
    return x | y

perm = list(itertools.permutations([0, 1, 2, 3]))[0]
res = (__OR__(
    __AND__(
        __OR__(arr[perm[0]], arr[perm[1]]), 
        __XOR__(arr[perm[2]], arr[perm[3]])),
    __XOR__(
        __AND__(arr[perm[1]], arr[perm[2]]),
        __OR__(arr[perm[0]], arr[perm[3]]))))
print(res)

# ans = 1
# i = 0
# while i < 24:
    # perm = list(itertools.permutations([0, 1, 2, 3]))[i]
    # res = (__OR__(
        # __AND__(
            # __OR__(arr[perm[0]], arr[perm[1]]), 
            # __XOR__(arr[perm[2]], arr[perm[3]])),
        # __XOR__(
            # __AND__(arr[perm[1]], arr[perm[2]]),
            # __OR__(arr[perm[0]], arr[perm[3]]))))
    # i += 1
    # ans = __AND__(ans, res)

# print(ans ^ 1)