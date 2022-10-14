def dlog(x, n):
  bigMod = 5 ** n
  ans = [None, 0, 1, 3, 2][x % 5]
  val = 2 ** ans % bigMod
  mod, phi = 5, 4
  phiVal = 2 ** phi % bigMod
  for i in range(2, n + 1):
    nextMod = mod * 5
    while val % nextMod != x % nextMod:
      val = val * phiVal % bigMod
      ans += phi
    phi *= 5
    phiVal = (phiVal *
              phiVal % bigMod *
              phiVal % bigMod *
              phiVal % bigMod *
              phiVal % bigMod)
    mod = nextMod
  return ans

def main():
  inp = input()
  n = len(inp)
  a = int(inp)
  for m in range(n + 1):
    l = a * 10 ** m
    x, mod = l, 2 ** (n + m)
    if x % mod != 0:
      x += mod - x % mod
    if x % 5 == 0:
      x += mod
    if x < l + 10 ** m:
      assert x % mod == 0 and x % 5 != 0
      x = x // mod
      mod = 5 ** (n + m)
      print(n + m + dlog(x % mod, n + m))
      return
  assert False

if __name__ == '__main__':
  cnt = int(input())
  for i in range(cnt):
    main()