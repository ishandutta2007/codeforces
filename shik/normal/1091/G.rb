require 'openssl'
require 'prime'

$stdout.sync = true

def ask(x)
  puts "sqrt #{x}"
  gets.to_i
end

def run(n)
  loop do
    a = rand(2..n - 1)
    g = n.gcd(a)
    return g if g != 1
    a2 = a * a % n
    next if a2.gcd(n) != 1
    r = ask(a2) % n
    next if r == -1 || r == a || r == n - a
    g = n.gcd(n + r - a)
    next if g == 1
    return g
  end
end

n = gets.to_i
fac = [n]

until fac.all?{|f| f.to_bn.prime?}
  x = run(n)
  nfac = []
  fac.each do |y|
    g = x.gcd(y)
    if g == 1 || g == y
      nfac << y
    else
      nfac << g << y / g
      x /= g
    end
  end
  fac << x if x > 1
  fac = nfac
end

puts "! #{fac.size} #{fac * ' '}"